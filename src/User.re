module GetUser = [%graphql
  {|
  query GetUser($login: String!) {
    user(login: $login) {
      bio
    }
  }
|}
];

module GetUserQuery = ReasonApollo.CreateQuery(GetUser);

let component = ReasonReact.statelessComponent("User");

let make = (~login, children) => {
  ...component,
  render: _ => {
    let userQuery = GetUser.make(~login, ());
    <GetUserQuery variables=userQuery##variables>
      ...(
           ({result}) =>
             switch (result) {
             | Loading => <div> (ReasonReact.string("Loading")) </div>
             | Error(error) =>
               <div> (ReasonReact.string(error##message)) </div>
             | Data(response) =>
               switch (response##user) {
               | Some(user) => children(user)
               | None => ReasonReact.string("User has no bio")
               }
             }
         )
    </GetUserQuery>;
  },
};